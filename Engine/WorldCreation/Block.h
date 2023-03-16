#pragma once

#include<cstdint>

/*Through those block I will decide what to do. Ie. Air means that nothing is displayed,
Water means that the block isn't solid, that is obvious, so then I have to deal with that problem etc..*/

/*TODO: Convert this implementation into a virtual Block class, and many inheriting block classes. Ie. Every block will have its own class with material struct in it.
To enable me to create some more complex looks of the game*/

enum class BlockType {
	Air = 0,
	Indestructible,
	Stone,
	Grass,
	Sand,
	Water,
};

class Block
{
protected:
	
	/*The basic info that is needed to effeciently create chunks*/

	BlockType m_BlockType;
	uint8_t m_BlockHeight;
	bool m_BlockTransparent;
	bool m_BlockSolid;

public:

	/*Constr/Destr*/
	
	inline Block(void) { m_BlockType = BlockType::Air, m_BlockHeight = 0; };
	inline Block(BlockType BlockType, uint8_t BlockHeight) { m_BlockType = BlockType, m_BlockHeight = BlockHeight; };
	~Block() {};

	/*Getters and Setters*/

	inline const BlockType GetType(void) { return m_BlockType; };
	inline const bool GetState(void) { return m_BlockType != BlockType::Air; };
	inline const uint8_t GetHeight(void) { return m_BlockHeight; };
	inline void SetType(BlockType Type) { m_BlockType = Type; };
	inline const void SetHeight(uint8_t CurrentHeight) { m_BlockHeight = CurrentHeight; };

	/*Overloaded operator made for comparing blocks*/

	friend bool operator==(const Block& original, const Block& compared)
	{
		return original.m_BlockType == compared.m_BlockType;
	}
};

