package database

import (
	"database/sql"
	"fmt"
	"log"
	"main/src/api/variables"
)

type IDatabase interface {
	createConnection() (*sql.DB, error)
	Log(input any) error
	InsertNewDropperCall(input any) error
	GetDropperBinary() (string, error)
}

type Database struct {
	Config variables.Config
}

func (db Database) GetDropperBinary() (string, error) {
	newDb, err := db.createConnection()
	defer newDb.Close()

	if err != nil {
		log.Printf("error trying to open db connection: %v", err)
		return "", err
	}

	q := `SELECT payload FROM Dropper where version='latest'`

	rows, err := newDb.Query(q)

	var dropperBinary string
	rows.Scan(dropperBinary)

	defer rows.Close()

	if err != nil {
		log.Printf("error querying: %v", err)
		return "", err
	}

	return dropperBinary, nil
}

// TODO: refactor this name
func (db Database) InsertNewDropperCall(input any) error {
	newDb, err := db.createConnection()
	defer newDb.Close()

	if err != nil {
		log.Printf("error trying to open db connection: %v", err)
		return err
	}

	q := `SELECT * FROM X`

	rows, err := newDb.Query(q, input)

	defer rows.Close()

	if err != nil {
		log.Printf("error querying: %v", err)
		return err
	}

	return nil
}

func (db Database) createConnection() (*sql.DB, error) {
	psqlconn := fmt.Sprintf("host=%s port=%d user=%s password=%s dbname=%s sslmode=disable",
		db.Config.Database.Hostname,
		db.Config.Database.Port,
		db.Config.Database.Username,
		db.Config.Database.Password,
		db.Config.Database.DatabaseName)

	database, err := sql.Open("postgres", psqlconn)

	if err != nil {
		return nil, err
	}

	return database, nil
}

func (db Database) Log(input any) error {
	// insert any input into database as json
	// db.Db.Query()
	return nil
}
