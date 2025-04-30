#include "mainwindow.h"
#include "/home/dimas/Документы/LR6/Task_1/Plant.h"

#include <QApplication>
#include <QDebug>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void textWork();
void arrayWork();
void structTextWork();
void structBinWork();
void addText();

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    std::ofstream fclear1("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_1.txt", std::ios::trunc);
    std::ofstream fclear2("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_2.bin", std::ios::trunc);
    std::ofstream fclear3("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_3.txt", std::ios::trunc);

    while (true)
    {
        int option = -1;
        std::cout << "1. Работа с текстом\n2. Работа с массивом\n3. Работа с массивом структур в текстовом файле\n4. Работа с массивом структур в бинарном файле\n5. Дозапись в текстовый файл предложения\nЛюбой другой символ - выход\n";
        std::cin >> option;

        switch (option)
        {
        case 1:
            textWork();
            break;
        case 2:
            arrayWork();
            break;
        case 3:
            structTextWork();
            break;
        case 4:
            structBinWork();
            break;
        case 5:
            addText();
            break;
        default:
            option = -1;
            break;
        }
        if (option == -1)
            break;
    }

    return 0;
}

void textWork()
{
    std::cout << "Введите абзац текста\n";
    std::string text;
    getchar();
    std::getline(std::cin, text);

    std::ofstream fclear("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20.txt", std::ios::trunc);
    std::ofstream fout("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20.txt", std::ios::in | std::ios::out);
    //qDebug() << text.size() << "\n";
    for (size_t i = 0; i < text.size(); i++)
    {
        fout << text[i];
    }
    fout.close();

    std::ifstream fin("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20.txt", std::ios::in);
    //fin.clear();
    //fin.seekg(0, std::ios::beg);
    std::string itext;
    char cur;
    while (fin >> std::noskipws >> cur)
    {
        itext += cur;
    }
    std::cout << itext << "\n";
    fin.close();
}

void arrayWork()
{
    std::cout << "Введите размер float массива\n";
    size_t sz;
    std::cin >> sz;
    std::cout << "Введите элементы\n";
    float arr[sz];
    for (size_t i = 0; i < sz; i++)
    {
        std::cin >> arr[i];
    }

    std::ofstream fclear("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_0.txt", std::ios::trunc);
    std::ofstream fout("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_0.txt", std::ios::in | std::ios::out);
    //qDebug() << text.size() << "\n";
    for (size_t i = 0; i < sz; i++)
    {
        fout << arr[i] << " ; ";
    }
    fout.close();

    std::ifstream fin("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_0.txt", std::ios::in);
    //fin.clear();
    //fin.seekg(0, std::ios::beg);
    float iarr[sz];
    size_t i = 0;
    std::string curnum = "";
    char cur;
    for (int i = 0; i < sz; i++)
    {
        while (fin >> cur)
        {
            if (cur == ';')
            {
                iarr[i++] = stof(curnum);
                curnum = "";
            }
            else
                curnum += cur;
        }
    }
    for (size_t i = 0; i < sz; i++)
    {
        std::cout << iarr[i] << " ";
    }
    std::cout << "\n";
    fin.close();
}

void structTextWork()
{
    Plant pl;
    std::cout << "Введите название\n";
    std::cin >> pl.name;
    std::cout << "Введите количество листьев\n";
    std::cin >> pl.num_leaves;
    for (int i  = 0; i < pl.num_leaves; i++)
    {
        std::cout << "Введите площадь листа " << i << "\n";
        std::cin >> pl.leave_area[i];
    }
    std::cout << "Введите код места\n";
    std::cin >> pl.code_place;
    std::cout << "Введите 1 если растение ядовито, 0 иначе\n";
    std::cin >> pl.is_toxic;
    std::cout << "Введите длину растения\n";
    std::cin >> pl.length;

    std::ofstream fout("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_1.txt", std::ios::in | std::ios::out | std::ios::app);
    fout << std::setprecision(6) << std::fixed;
    fout << pl.name << " ";
    fout << pl.num_leaves << " ";
    for (int i  = 0; i < pl.num_leaves; i++)
    {
        fout << pl.leave_area[i] << " ";
    }
    fout <<  pl.code_place << " ";
    fout <<  pl.is_toxic << " ";
    fout <<  pl.length << "\n";
    fout.close();

    std::ifstream fin("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_1.txt", std::ios::in);
    while (fin >> pl.name)
    {
        pl.name[50] = '\0';
        fin >> pl.num_leaves;
        for (int i = 0; i < pl.num_leaves; i++)
        {
            fin >> pl.leave_area[i];
        }
        fin >> pl.code_place;
        fin >> pl.is_toxic;
        fin >> pl.length;

        std::cout << const_cast<const char*>(pl.name) << " ";
        std::cout << pl.num_leaves << " ";
        for (int i  = 0; i < pl.num_leaves; i++)
        {
            std::cout << pl.leave_area[i] << " ";
        }
        std::cout << pl.code_place << " ";
        std::cout << pl.is_toxic << " ";
        std::cout << std::setprecision(6) << std::fixed << pl.length << "\n";
    }
    fin.close();
}

void structBinWork()
{
    Plant pl;
    std::cout << "Введите название\n";
    std::cin >> pl.name;
    std::cout << "Введите количество листьев\n";
    std::cin >> pl.num_leaves;
    for (int i  = 0; i < pl.num_leaves; i++)
    {
        std::cout << "Введите площадь листа " << i << "\n";
        std::cin >> pl.leave_area[i];
    }
    std::cout << "Введите код места\n";
    std::cin >> pl.code_place;
    std::cout << "Введите 1 если растение ядовито, 0 иначе\n";
    std::cin >> pl.is_toxic;
    std::cout << "Введите длину растения\n";
    std::cin >> pl.length;

    std::ofstream fout("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_2.bin", std::ios::in | std::ios::out | std::ios::app | std::ios::binary);
    fout << std::setprecision(6) << std::fixed;
    //qDebug() << sizeof(pl.name);
    pl.name[50] = '\0';
    fout.write((char*)&pl.name, sizeof(pl.name));
    fout.write((char*)&pl.num_leaves, sizeof(int));
    for (int i  = 0; i < pl.num_leaves; i++)
    {
        fout.write((char*)&pl.leave_area[i], sizeof(int));
    }
    fout.write((char*)&pl.code_place, sizeof(char));
    fout.write((char*)&pl.is_toxic, sizeof(bool));
    fout.write((char*)&pl.length, sizeof(double));
    fout.close();

    std::ifstream fin("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_2.bin", std::ios::in);
    while (fin.read((char*)&pl.name, sizeof(pl.name)))
    {
        pl.name[50] = '\0';
        fin.read((char*)&pl.num_leaves, sizeof(pl.num_leaves));
        for (int i = 0; i < pl.num_leaves; i++)
        {
            fin.read((char*)&pl.leave_area[i], sizeof(pl.leave_area[i]));
        }
        fin.read((char*)&pl.code_place, sizeof(pl.code_place));
        fin.read((char*)&pl.is_toxic, sizeof(pl.is_toxic));
        fin.read((char*)(&pl.length), sizeof(pl.length));

        std::cout << const_cast<const char*>(pl.name) << ";";
        std::cout << pl.num_leaves << ";";
        for (int i = 0; i < pl.num_leaves; i++)
        {
            std::cout << pl.leave_area[i] << " ";
        }
        std::cout << ";" << pl.code_place << ";";
        std::cout << pl.is_toxic << ";";
        std::cout << std::setprecision(6) << std::fixed << pl.length << ";\n";
    }
    fin.close();
}

void addText()
{
    std::cout << "Введите предложение текста\n";
    std::string text;
    getchar();
    std::getline(std::cin, text);

    std::ofstream fout("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_3.txt", std::ios::in | std::ios::out | std::ios::app);
    //qDebug() << text.size() << "\n";
    fout << text << "\n";
    fout.close();

    std::ifstream fin("/home/dimas/Документы/LR6/Task_2/ЛуканскийЛаб20_3.txt", std::ios::in);
    //fin.clear();
    //fin.seekg(0, std::ios::beg);
    std::string itext;
    while (std::getline(fin, itext))
    {
        std::cout << itext << "\n";
    }
    fin.close();
}
