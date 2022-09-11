package variables

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type DatabaseConfig struct {
	Hostname     string
	Port         int
	DatabaseName string
	Username     string
	Password     string
}

type Config struct {
	DropperPath    string
	ExecutablePath string
	Database       DatabaseConfig
}

func IsNullOrEmpty(s string) bool {
	return len(strings.TrimSpace(s)) == 0
}

func GetConfig() Config {
	return Config{
		DropperPath:    "/home/user/dropper.exe",
		ExecutablePath: "/home/user/executable.exe",
		Database:       GetDatabaseConfig(),
	}
}

func GetEnvVariables(key, defaultValue string) string {
	value, found := os.LookupEnv(key)
	if found && !IsNullOrEmpty(value) {
		return value
	}
	return defaultValue
}

func GetDatabaseConfig() DatabaseConfig {
	host := GetEnvVariables("DB_HOSTNAME", "")
	port := GetEnvVariables("DB_PORT", "")
	dbName := GetEnvVariables("DB_NAME", "")
	username := GetEnvVariables("DB_USERNAME", "")
	password := GetEnvVariables("DB_PASSWORD", "")
	portNum, err := strconv.Atoi(port)

	if err != nil {
		panic(fmt.Sprintf("invalid database port config: %s", port))
	}

	return DatabaseConfig{
		Hostname:     host,
		Port:         portNum,
		DatabaseName: dbName,
		Username:     username,
		Password:     password,
	}
}
