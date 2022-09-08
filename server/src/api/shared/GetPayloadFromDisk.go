package shared

import (
	"io/ioutil"
	"log"
)

func GetPayloadFromDisk(path string) []byte {
	content, err := ioutil.ReadFile(path)
	if err != nil {
		log.Printf("unable to read file: %v", err)
	}
	return content
}
