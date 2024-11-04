package service

import (
	"fmt"
	"os"
)

func GetEnvVariable(name string, defaultValue string) (string, error) {
	env_var := os.Getenv(name)
	if env_var == "" {
		return defaultValue, fmt.Errorf("cannot read env variable: %s", name)
	}
	return env_var, nil
}
