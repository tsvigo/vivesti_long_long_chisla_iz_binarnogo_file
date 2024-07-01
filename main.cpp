//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}
//###########################################################################
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream inputFile(
        "/home/viktor/my_projects_qt_2/sgenerirovaty_long_long_neyroni/random_numbers.bin",
        std::ios::binary);

    if (!inputFile) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    // Определяем размер файла
    inputFile.seekg(0, std::ios::end);
    std::streamsize fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    // Проверка, что размер файла кратен размеру long long
    if (fileSize % sizeof(long long) != 0) {
        std::cerr << "Некорректный размер файла." << std::endl;
        return 1;
    }

    // Читаем файл
    std::vector<long long> numbers(fileSize / sizeof(long long));
    inputFile.read(reinterpret_cast<char *>(numbers.data()), fileSize);

    if (!inputFile) {
        std::cerr << "Ошибка чтения файла." << std::endl;
        return 1;
    }

    // Выводим числа на экран
    for (const long long &number : numbers) {
        std::cout << number << std::endl;
    }

    return 0;
}
