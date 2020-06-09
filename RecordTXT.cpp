//
// Created by iscle on 9/6/20.
//

#include "RecordTXT.hpp"
#include "Utils.hpp"

RecordTXT::RecordTXT() : Record(TXT) {

}

RecordTXT::RecordTXT(std::string name, std::list<std::pair<std::string, std::string>> values) : RecordTXT() {
    setName(name);
    this->values = values;
}

RecordTXT::RecordTXT(std::string name, std::string map) : RecordTXT() {
    setName(name);
    this->values = std::list<std::pair<std::string, std::string>>();
    std::vector<std::string> q = split(map, ", *");
    for (std::string s : q) {
        std::vector<std::string> kv = split(s, "=");
        if (kv.size() == 2)
            values.emplace_back(std::pair<std::string, std::string>(kv[0], kv[1]));
    }
}

std::list<std::pair<std::string, std::string>> RecordTXT::getValues() {
    return values;
}

void RecordTXT::readData(int len, std::stringbuf &in) {
    int end = in.position() + len;
    values = new LinkedHashMap<>();
    while (in.position() < end) {
        int slen = in.get() & 0xFF;
        StringBuilder sb = new StringBuilder(slen);
        for (int i = 0; i < slen; i++) sb.append((char) in.get());

        String value = sb.toString();
        int ix = value.indexOf("=");
        if (ix > 0) values.put(value.substring(0, ix), value.substring(ix + 1));
    }
}

int RecordTXT::writeData(std::stringbuf &out, Packet &packet) {
    if (!values.empty()) {
        int len = 0;
        for (auto const &i : values) {
            std::string value = i.first + i.second;
            out.
        }
        for (Map.Entry < String, String > e : values.entrySet()) {
            String value = e.getKey() + "=" + e.getValue();
            out.put((byte) value.length());
            out.put(value.getBytes(StandardCharsets.UTF_8));
            len += value.length() + 1;
        }
        return len;
    } else {
        return -1;
    }
}
