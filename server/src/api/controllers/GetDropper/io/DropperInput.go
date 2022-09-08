package io

import (
	"main/src/api/shared/io"
	"time"
)

type DropperInput struct {
	OS   io.OS
	Date time.Time // the date that the dropper is executed
	Ip   string
}
