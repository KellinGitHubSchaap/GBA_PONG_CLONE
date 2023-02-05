#ifndef BG_ATTRIBUTES_HPP
#define BG_ATTRIBUTES_HPP

#define BG_4BPP			 0	//!< 16 colored background 

// Regular Only Attributes
#define BG_REGULAR_32x32		0		//!< reg bg, 32x32 (256x256 px) | Regular bg's only
#define BG_REGULAR_64x32		0x4000	//!< reg bg, 64x32 (512x256 px) | Regular bg's only
#define BG_REGULAR_32x64		0x8000	//!< reg bg, 32x64 (256x512 px) | Regular bg's only
#define BG_REGULAR_64x64		0xC000	//!< reg bg, 64x64 (512x512 px) | Regular bg's only

#define BG_PRIORITY_MASK	0x0003						//!< Priority of a background layer (0 == highest - 3 == lowest)
#define BG_PRIORITY_SHIFT	0							//!< Bit position
#define BG_PRIORITY(n)		((n) << BG_PRIORITY_SHIFT)	//!< Place the mask value on the correct bit position

#define BG_CHARBLOCK_BASE_MASK		0x000C	//!< Sets the charblock (tile-block) that serves as the base for the tile | values 0 - 3
#define BG_CHARBLOCK_BASE_SHIFT		2	
#define BG_CHARBLOCK_BASE(n)		((n) << BG_CHARBLOCK_BASE_SHIFT)

#define BG_SCREENBLOCK_BASE_MASK	0x1F00	//!< Sets the screenblock that serves as the base for screen-entry/tile-map | values 0 - 31
#define BG_SCREENBLOCK_BASE_SHIFT		 8	
#define BG_SCREENBLOCK_BASE(n)		((n) << BG_SCREENBLOCK_BASE_SHIFT)

#define BG_SIZE_MASK	0xC000	//!< Regular and affine bg's have different sizes available to them. 
#define BG_SIZE_SHIFT		14
#define BG_SIZE(n)		((n) << BG_SIZE_SHIFT)

#define BG_BUILD(charblockBase, screenblockBase, size, bpp, priority, mosaic, wrap) \
(																					\
	((size)<<14) | (((wrap)&1)<<13)	| (((screenblockBase)&31)<< 8)					\
	|	(((bpp)&8)<<4)	|	(((mosaic)&1)<<6)	| (((charblockBase)&3)<<2)			\
	|	((priority)&3)																\
)

#endif // BG_ATTRIBUTES_HPP