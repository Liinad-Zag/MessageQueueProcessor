#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HandoverCancel.h"
// Функция для записи документа в JSON файл
void WriteDocumentToFile(const rapidjson::Document& document, const std::string& filePath)
{
    // Создаем буфер для записи JSON
    rapidjson::StringBuffer buffer;
    // Создаем writer для записи JSON в буфер
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    // Записываем документ в writer
    document.Accept(writer);

    // Открываем файл для записи
    std::ofstream file(filePath);
    if (file.is_open()) {
        // Записываем содержимое буфера в файл
        file << buffer.GetString();
        // Закрываем файл
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
    }
}
rapidjson::Document CreateDocumentFromJsonFile(const std::string& filePath) {
    std::ifstream file(filePath); // Открытие файла для чтения
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filePath << std::endl;
        return rapidjson::Document(); // Возвращаем пустой документ
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Чтение содержимого файла в stringstream
    file.close(); // Закрытие файла

    rapidjson::Document document;
    document.Parse(buffer.str().c_str()); // Парсинг JSON из строки

    if (document.HasParseError()) {
        std::cerr << "Ошибка парсинга JSON файла " << filePath << std::endl;
        return rapidjson::Document(); // Возвращаем пустой документ в случае ошибки
    }

    return document;
}
int main()
{
    rapidjson::Document config;
    std::string JSONPath = "HandoverCancel.json";
    std::string NewJSONPath = "NewHandoverCancel.json";
    rapidjson::Document document = CreateDocumentFromJsonFile(JSONPath);
    rapidjson::Document newDocument;
    JSONModels::HandoverCancel handoverCancel;
    handoverCancel.Deserialize(document);

    //handoverCancel.Cp_ue_id(1);
    //handoverCancel.Cause(RrcCause::CAUSE_RADIO_NETWORK);
    //handoverCancel.Rrc_cause_value_t(1);
    // print some value.
     std::cout << handoverCancel.GetDetailedCause() << std::endl;

    // save json to new file.
    handoverCancel.Serialize(newDocument);
    WriteDocumentToFile(newDocument, NewJSONPath);
}