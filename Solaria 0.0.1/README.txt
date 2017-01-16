Solaria 0.0.1

Notes:
Added command line
	Quit
	Ping
	Clear
	Print
	Create
		Ship Entity
	Delete
		Ship Entity
Point movement simulator

Console commands
	Quit game
		"quit"
	Close console
		"close"
	Clear terminal screen
		"clear"
	Test ping to consolecmd class
		"ping"
	Print data
		"print <type> <id>"
		Types
			"ship"
		ID
			"int"
				Number of the entity in the vector
			"all"
				Prints all ship addresses
	Create entity
		"create <type> <id>"
		Types
			"ship"
		ID
			"int"
				ID for the ship type, 0 for xship
	Delete entity
		"delete <type> <id>
		Types
			"ship"
		ID
			"int"
	Simulation testing
		"sim" <id>
		ID
			"int"
		

Variable conventions:
	module size
		-1 = invalid
		0 = fighter
		1 = small
		2 = medium
		3 = large
	module damages
		NULL pointer = No module
		-1 = offline
		0 = functioning
		1 = damaged
		2 = destroyed

	mod_hardpoint
		type
			-1 = invalid
			0 = autocannon
			1 = railgun
	Hyperdrive
		Intra drive speed in AU
		Inter drive speed in LY

Simulation
	W and S for Z axis
	D and A for X axis
	Left shift and alt for Y axis
	C to clear position and velocity
	ESC to exit simulation to the console