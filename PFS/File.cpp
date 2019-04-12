#include "File.h"



File::File(Storage * storage){
	this->descripor = FileDescriptor(storage);
}


File::~File(){
	delete this->permissions;
}

bool File::create(){
	return descripor.create(default_file_size);
}

FileDataStream File::open(char flags){
	return FileByteStream(&descripor);
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
	delete this->permissions;
	this->permissions = new FilePermissions(permissions);
}

FilePermissions File::get_permissions() const{
	return *permissions;
}

FileId File::get_id() const {
	return descripor.get_pointer();
}


