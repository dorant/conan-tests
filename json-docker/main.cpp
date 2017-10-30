#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

int main()
{
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);

    writer.StartObject();
    writer.Key("hello");
    writer.String("world");
    writer.EndObject();

    std::cout << s.GetString() << std::endl;
}
