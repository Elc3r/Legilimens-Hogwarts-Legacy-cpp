#include "decompress.h"
#include "oodle.h"

bool decompressDb(std::string& dbData, bool verbose) {
    UProperty prop;
    UArrayProperty arr;

    arr.type.length = 0;
    arr.type.data = nullptr;
    arr.unknown = 0;
    arr.size = static_cast<uint32_t>(dbData.size());
    arr.value = malloc(arr.size);
    memcpy(arr.value, dbData.data(), arr.size);

    prop.length = arr.size + UARRAYPROPERTY_ADDED_LENGTH;
    prop.data = &arr;

    decompress(&prop, verbose);

    dbData.assign(reinterpret_cast<char*>(arr.value), arr.size);
    free(arr.value);

    return true;
}