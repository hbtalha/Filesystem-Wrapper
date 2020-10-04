#ifndef FS_WRAP_H_INCLUDED
#define FS_WRAP_H_INCLUDED

#include <vector>
#include <filesystem>

namespace fs_dir
{
enum class mode {FOLDER = 0, FILE};

int number_of_files_in_directory(std::filesystem::path file_path);
int number_of_folders_in_directory(std::filesystem::path file_path);
void files_in_directory(std::filesystem::path file_path, std::vector<std::filesystem::path>& files);
void folders_in_directory(std::filesystem::path file_path, std::vector<std::filesystem::path>& folders);

std::vector<std::filesystem::path> files_in_directory(std::filesystem::path file_path);
std::vector<std::filesystem::path> folders_in_directory(std::filesystem::path file_path);

int number_of_files_in_directory_recursively(std::filesystem::path file_path);
int number_of_folders_in_directory_recursively(std::filesystem::path file_path);
void files_in_directory_recursively(std::filesystem::path file_path, std::vector<std::filesystem::path>& files);
void folders_in_directory_recursively(std::filesystem::path file_path, std::vector<std::filesystem::path>& folders);

std::vector<std::filesystem::path> files_in_directory_recursively(std::filesystem::path file_path);
std::vector<std::filesystem::path> folders_in_directory_recursively(std::filesystem::path file_path);

void get_files_by_extension_in_directory(std::filesystem::path file_path, std::string extension,
        std::vector<std::filesystem::path>& files);
void get_files_by_extension_in_directory_recursively(std::filesystem::path file_path, std::string extension,
        std::vector<std::filesystem::path>& files);

std::vector<std::filesystem::path> get_files_by_extension_in_directory(std::filesystem::path file_path, std::string extension);
std::vector<std::filesystem::path> get_files_by_extension_in_directory_recursively(std::filesystem::path file_path, std::string extension);

int number_of_files_by_extension_in_directory(std::filesystem::path file_path, std::string extension);
int number_of_files_by_extension_in_directory_recursively(std::filesystem::path file_path, std::string extension);

}

#endif // FS_WRAP_H_INCLUDED
