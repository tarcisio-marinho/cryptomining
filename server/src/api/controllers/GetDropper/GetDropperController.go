package GetDropper

import (
	"github.com/gin-gonic/gin"
	"log"
	input "main/src/api/controllers/GetDropper/io"
	"main/src/application/useCases/GetDropper"
	"net/http"
)

type GetDropperController struct {
	UseCase GetDropper.IGetDropperUseCase
}

func (controller GetDropperController) Get(c *gin.Context) {

	var payload input.DropperInput
	err := c.BindJSON(&payload)

	if err != nil {
		log.Printf("incorrect input format: %v", err)
		// TODO: log if someone is trying to check the api ?
		return
	}

	payloadAsB64, err := controller.UseCase.Execute(payload)

	if err != nil {
		log.Printf("error occurred: %v", err)
		c.IndentedJSON(http.StatusOK, "")
		return
	}

	response := struct {
		Payload string
	}{
		Payload: payloadAsB64,
	}

	c.IndentedJSON(http.StatusOK, response)
}
