#include "FileStream.h"


FileStream::FileStream(Storage *storage): descriptor(FileDescriptor(nullptr)){
	chunk = storage->allocate(1);
	descriptor = FileDescriptor(storage, chunk);
}

FileStream::~FileStream(){
//	delete descriptor;
}

FileByteStream* FileStream::open(){
	return new FileByteStream(&descriptor);
}

void FileStream::erase(){
	descriptor.delete_file();
}
