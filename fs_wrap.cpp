#include <stdexcept>

#include "fs_wrap.h"

using namespace std;
using namespace std::filesystem;

namespace fs_dir
{

int number_of_entities_in_directory(path file_path, mode type)
{
    int counter = 0;

    if ( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(type == mode::FILE && is_regular_file(it))
            ++counter;
        else if(type == mode::FOLDER && is_directory(it))
            ++counter;
    }

    return counter;
}

vector<path> entities_in_directory(path file_path, mode type)
{
    vector<path> entities;

    if ( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(type == mode::FILE && is_regular_file(it))
            entities.push_back(it.path().filename());
        else if(type == mode::FOLDER && is_directory(it))
            entities.push_back(it.path().filename());
    }

    return entities;
}

int number_of_entities_in_directory_recursively(path file_path,
        mode type)
{
    int counter = 0;

    if ( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(type == mode::FILE && is_regular_file(it))
            ++counter;
        else if(type == mode::FOLDER && is_directory(it))
            ++counter;
    }

    return counter;
}

vector<path> entities_in_directory_recursively(path file_path,
        mode type)
{
    vector<path> entities;

    if ( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(type == mode::FILE && is_regular_file(it))
            entities.push_back(it.path().filename());
        else if(type == mode::FOLDER && is_directory(it))
            entities.push_back(it.path().filename());
    }

    return entities;
}

int number_of_files_in_directory(path file_path)
{
    if(file_path.empty())
        return 0;

    return number_of_entities_in_directory(file_path, mode::FILE);
}

int number_of_folders_in_directory(path file_path)
{
    if(file_path.empty())
        return 0;

    return number_of_entities_in_directory(file_path, mode::FOLDER);
}

void files_in_directory(path file_path, vector<path>& files)
{
    if(file_path.empty())
        return;

    files = entities_in_directory(file_path, mode::FILE);
}

void folders_in_directory(path file_path, vector<path>& folders)
{
    if(file_path.empty())
        return;

    folders = entities_in_directory(file_path, mode::FOLDER);
}

vector<path> files_in_directory(path file_path)
{
   vector<path> files;
   files_in_directory(file_path, files);

   return files;
}
vector<path> folders_in_directory(path file_path)
{
   vector<path> folders;
   folders_in_directory(file_path, folders);

   return folders;
}

int number_of_files_in_directory_recursively(path file_path)
{
    if(file_path.empty())
        return 0;

    return number_of_entities_in_directory_recursively(file_path, mode::FILE);
}

int number_of_folders_in_directory_recursively(path file_path)
{
    if(file_path.empty())
        return 0;

    return number_of_entities_in_directory_recursively(file_path, mode::FOLDER);;
}

void files_in_directory_recursively(path file_path,
        vector<path>& files)
{
    if(file_path.empty())
        return;

    files = entities_in_directory_recursively(file_path, mode::FILE);
}

void folders_in_directory_recursively(path file_path,
        vector<path>& folders)
{
    if(file_path.empty())
        return;

    folders = entities_in_directory_recursively(file_path, mode::FOLDER);
}

vector<path> files_in_directory_recursively(path file_path)
{
   vector<path> files;
   files_in_directory_recursively(file_path, files)   ;

   return files;
}

vector<path> folders_in_directory_recursively(path file_path)
{
   vector<path> folders;
   folders_in_directory_recursively(file_path, folders)   ;

   return folders;
}

int number_of_files_by_extension_in_directory(path file_path,
        string extension)
{
    int counter = 0;

    size_t containsDot = extension.find(".");

    if (containsDot == string::npos)
        extension.insert(0, ".");

    if( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    if(filesystem::is_empty(file_path))
        return 0;

    if(exists(file_path))
        for(const auto& it : std::filesystem::directory_iterator(file_path))
        {
            if(is_regular_file(it) && it.path().extension() == extension)
                ++counter;
        }

    return counter;
}

int number_of_files_by_extension_in_directory_recursively(path file_path,
        string extension)
{
    int counter = 0;

    size_t containsDot = extension.find(".");

    if (containsDot == string::npos)
        extension.insert(0, ".");

    if( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(is_regular_file(it) && it.path().extension() == extension)
            ++counter;
    }

    return counter;
}

void get_files_by_extension_in_directory(filesystem::path file_path, string extension,
        vector<filesystem::path>& files)
{
    size_t containsDot = extension.find(".");

    if (containsDot == string::npos)
        extension.insert(0, ".");

    if( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(is_regular_file(it) && it.path().extension() == extension)
            files.push_back(it.path().filename());
    }
}

void get_files_by_extension_in_directory_recursively(path file_path,
        string extension, vector<path>& files)
{
    size_t containsDot = extension.find(".");

    if (containsDot == string::npos)
        extension.insert(0, ".");

    if( ! exists(file_path) || ! is_directory(file_path))
    {
        throw runtime_error("directory does not exist");
    }

    for(const auto& it : std::filesystem::directory_iterator(file_path))
    {
        if(is_regular_file(it) && it.path().extension() == extension)
            files.push_back(it.path().filename());
    }
}

vector<path> get_files_by_extension_in_directory(path file_path, string extension)
{
   vector<path> files;
   get_files_by_extension_in_directory(file_path, extension, files);

   return files;
}

vector<path> get_files_by_extension_in_directory_recursively(path file_path, string extension)
{
   vector<path> files;
   get_files_by_extension_in_directory_recursively(file_path, extension, files);

   return files;
}

} // fs_dir namespace
