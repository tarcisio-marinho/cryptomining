package database

import "database/sql"

type IDatabase interface {
	Log(input any) error
}

type Database struct {
	Db *sql.DB
}

func (db Database) Log(input any) error {
	// insert any input into database as json
	// db.Db.Query()
	return nil
}
