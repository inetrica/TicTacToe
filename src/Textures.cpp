
#include "Textures.h"

namespace textures{
	int load(){
		if(!x_texture.loadFromFile("Graphics/Game/xval.png")){
			return -1;
		}

		if(!o_texture.loadFromFile("Graphics/Game/oval.png")){
			return -1;
		}

		if(!e_texture.loadFromFile("Graphics/Game/empty.png")){
			return -1;
		}

		return 0;
	}

	sf::Texture x_texture;
	sf::Texture o_texture;
	sf::Texture e_texture;
	
}
