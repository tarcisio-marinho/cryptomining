# Server

- Download the dropper -> URL to download the dropper binary
- Download the executable -> dropper will hit this endpoint to download the executable binary -> specific for each OS (linux, windows, macOs ...)
- executable connect -> when executable start running hit this endpoint first - send info about the infected machine and get pool info and so on ...
- executable IsAlive -> executable hits this endpoint so the server knows who's active mining - hit every X mins
