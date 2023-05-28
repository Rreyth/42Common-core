#include <iostream>
#include <fstream>

std::string outname(char *name)
{
    std::string out = name;

    out += ".replace";
    return (out);
}

std::string search_replace(std::string str, std::string s1, std::string s2)
{
    size_t i = 0;
    size_t start = 0;
    std::string new_str;

    while (i != std::string::npos)
    {
        i = str.find(s1, start);
        if (i == std::string::npos)
            break;
        new_str += str.substr(start, i - start);
        new_str += s2;
        start = i + s1.length();
    }
    new_str += str.substr(start, str.length() - start);
    return (new_str);
}

void    read_and_write(char *name, char *s1, char *s2)
{
    std::ifstream file(name, std::ifstream::in);

    if (!file.is_open())
    {
        std::cout << "Could not open : " << name << std::endl;
        return ;
    }

    std::ofstream output(outname(name).c_str(), std::ofstream::out);

    if (!output.is_open())
    {
        std::cout << outname(name) << ": Permission denied" << std::endl;
        return;
    }

    std::string line;
    std::string final;

    std::getline(file, line);
    while (file)
    {
        final += line + '\n';
        std::getline(file, line);
    }
    final = search_replace(final, s1, s2);
    output << final;
    file.close();
    output.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid number of args" << std::endl;
        return (1);
    }
    read_and_write(argv[1], argv[2], argv[3]);
    return (0);
} 