package variables

type Config struct {
	DropperPath    string
	ExecutablePath string
}

func GetConfig() Config {
	return Config{
		DropperPath:    "/home/user/dropper.exe",
		ExecutablePath: "/home/user/executable.exe",
	}
}
