package middlewares

import (
	"github.com/gin-gonic/gin"
	"log"
	"main/src/infrastructure/database"
)

func LoggerMiddleware(db database.IDatabase) gin.HandlerFunc {
	return func(c *gin.Context) {
		input := "asdfasd"

		err := db.Log(input)

		if err != nil {
			// c.AbortWithStatusJSON(http.StatusBadRequest, "err")
			log.Printf("error logging into DB: %v", err)
		}

		c.Next()
	}
}
