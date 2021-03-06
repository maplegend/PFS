#include "File.h"



File::File(Storage * storage, Path path): path(path), stream_table(StreamTable(storage)), descripor(FileDescriptor(storage)){
	create();
}


File::~File(){
	//delete this->permissions;
	//delete stream_table;
}

bool File::create(){
	return descripor.create(default_file_size);
}

void File::delete_file(){
	descripor.delete_file();
}

FileDataStream *File::open(char flags){
	return new FileByteStream(&descripor);
}

FileByteStream* File::open_stream(std::string name){
	FileStream* stream = stream_table.get_stream(name);
	if (!stream) stream = stream_table.create_stream(name);
	return stream->open();
}

std::vector<std::string> File::get_streams(){
	return stream_table.get_streams();
}

void File::delete_stream(std::string name, bool full){
	stream_table.delete_stream(name, full);
}

bool File::is_directory() const{
	return false;
}

std::string File::get_name() const{
	return name;
}

void File::set_name(std::string name){
	this->name = name;
}

std::time_t File::get_created_data() const {
	return created_date;
}

void File::set_created_data(std::time_t created_date){
	this->created_date = created_date;
}

std::time_t File::get_modified_data() const {
	return modified_date;
}

void File::set_modified_data(std::time_t modified_date){
	this->modified_date = modified_date;
}

void File::set_permissions(FilePermissions permissions){
	//delete permissions;
	permissions = new FilePermissions(permissions);
}

FilePermissions File::get_permissions() const{
	return permissions;
}

FileId File::get_id() const {
	return descripor.get_pointer();
}

void File::set_path(Path path){
	this->path = path;
}

Path File::get_path() const{
	return path;
}


