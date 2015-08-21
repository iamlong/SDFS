#ifndef rprocess_h
#define rprocess_h

#include <string>
#include "../util/utils.h"
#include "../util/stdtype.h"

using namespace std;

	/**
	 *	rprocess is used to describe a remote process which is opening file for read or write
	*/
struct rprocess{
	public:
		char m_hash[DIGEST_LEN];
		int process;	//process number which open the file, -1 if the process is dead
		char host[256];	//remote host ip or host name
};

	/**
	 *	memblock is used to describe memory block which is used for serialization and deserialization
	*/
struct memblock{
	
	public:
		unsigned int size;	//remote host ip or host name
		char mem[];	
	
};

enum sinode_type{
	
	file = 1,
	path = 2,
	link = 3
};

struct nodebase{
	static const int hash_size = DIGEST_LEN;
	char m_hash[DIGEST_LEN];
	string m_path;
	sinode_type m_type;
	uint32_t m_permission;
	uint32_t m_size_in_block;
	uint32_t m_size_in_byte;
	time_t m_create_time;
	time_t m_modified_time;
	time_t m_access_time;
	time_t m_change_time;
};
#endif
