#ifndef storage_command_h
#define storage_command_h

#include "../util/serialize.h"
#include "stdlib.h"
#include "../util/sig.h"

class storage_command: public ISerialize{
	
	public:
		//serializer and deserializer
		sd_uint32_t getPersistentSizeInByte();
		bool Serialize(Serializer * inSerializer);
		bool DeSerialize(DeSerializer * inDeSerializer);

		void init(); //initialize Storage_Command
		storage_command(sd_uint32_t maxsize);

		bool CreateCommand(string filename, sd_uint8_t * buff, sd_uint32_t buff_size);
		bool ReadCommand(string filename); 
		bool DeleteCommand(string filename);


	private:
		sd_uint32_t m_max_buff_size;
		string m_command;
		string m_filename;
		sd_uint32_t m_buff_size;
		sd_uint8_t * m_buff;
		bool setCommand(string command, string filename, sd_uint8_t * buff, sd_uint32_t buff_size);

};

#endif
