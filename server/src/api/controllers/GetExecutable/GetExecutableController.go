package GetExecutable

import (
	"encoding/base64"
	"github.com/gin-gonic/gin"
	"main/src/api/shared/io"
	"net/http"
)

type GetExecutableController struct {
	Payload io.Payload
}

func (controller GetExecutableController) Get(c *gin.Context) {
	payloadAsB64 := base64.StdEncoding.EncodeToString(controller.Payload.Bytes)

	response := struct {
		Payload string
	}{
		Payload: payloadAsB64,
	}

	c.IndentedJSON(http.StatusOK, response)
}
