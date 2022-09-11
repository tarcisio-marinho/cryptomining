CREATE DATABASE "Cryptominer"
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    CONNECTION LIMIT = -1;

CREATE TABLE public."Dropper"
(
    id serial NOT NULL,
    payload text NOT NULL,
    name text NOT NULL,
    version text NOT NULL,
    "targetOs" text NOT NULL,
    PRIMARY KEY (id)
);

ALTER TABLE IF EXISTS public."Dropper"
    OWNER to postgres;