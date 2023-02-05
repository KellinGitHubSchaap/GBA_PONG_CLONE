
//{{BLOCK(player)

//======================================================================
//
//	player, 16x16@4, 
//	+ palette 4 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 8 + 128 = 136
//
//	Time-stamp: 2023-02-04, 17:26:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int playerTiles[32] __attribute__((aligned(4)))=
{
	0x11110000,0x22211000,0x33221000,0x23332100,0x22222100,0x11112100,0x31311000,0x31321000,
	0x00001111,0x00011222,0x00012323,0x00123312,0x00123211,0x00122133,0x00011313,0x00012313,
	0x33211000,0x11113100,0x21123100,0x13122100,0x33211000,0x22110000,0x11110000,0x11111000,
	0x00011233,0x00131111,0x00132112,0x00122131,0x00011233,0x00001122,0x00001111,0x00011111,
};

const unsigned int playerPal[2] __attribute__((aligned(4)))=
{
	0x00007C1F,0x63FF001F,
};

//}}BLOCK(player)
