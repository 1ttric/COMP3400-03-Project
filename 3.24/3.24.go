package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strconv"
)

const (
	port  = 5575
	haiku = `over the wintry
forest, winds howl in rage
with no leaves to blow`
)

func main() {
	// Listen
	sock, err := net.Listen("tcp", ":"+strconv.Itoa(port))
	defer sock.Close()
	if err != nil {
		fmt.Println("error listening on socket: ", err.Error())
		os.Exit(1)
	}
	fmt.Println("Listening for connections...")

	for {
		// Accept a client connection
		conn, err := sock.Accept()
		defer conn.Close()
		if err != nil {
			fmt.Println("error accepting connection: ", err.Error())
			os.Exit(1)
		}

		// Concurrency!
		go func() {
			fmt.Println("Sending haiku to", conn.RemoteAddr().String())
			writer := bufio.NewWriter(conn)
			writer.WriteString(haiku)
			writer.Flush()
			conn.Close()
		}()
	}
}
