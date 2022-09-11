package GetDropper

import (
	"main/src/api/shared/io"
	"main/src/infrastructure/database"
)

type IGetDropperUseCase interface {
	Execute(input any) (string, error)
}

type GetDropperUseCase struct {
	Database database.IDatabase
	Payload  io.Payload
}

func (useCase GetDropperUseCase) Execute(input any) (string, error) {

	useCase.Database.InsertNewDropperCall(input)

	return useCase.Payload.BytesAsB64, nil
}
