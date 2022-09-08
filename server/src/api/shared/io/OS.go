package io

type OS struct {
	Name    string
	Version string
	UUID    string // Could be GUID (windows) / machine-id (linux)
}
