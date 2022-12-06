/*
    Taken from: https://github.com/Tvde1/ConfigTool on 12-4-22.
        Name:	ConfigTool.h
        Author:	Tvde1
*/
#pragma once

#include <iostream>
#include <map>
#include <string>
#include "StringUtils.h"

using namespace std;

// #include "ArduinoJson.h"

struct BaseVar {
        string name;
        // virtual void serialize(JsonObject*) = 0;
        // virtual void deserialize(JsonObject*) = 0;
        virtual void reset() = 0;
        virtual string toString() = 0;
        virtual void fromString(string) = 0;
};

template <typename T>
struct ConfigVar : BaseVar {
        ConfigVar(string n, T* p){};

        // void deserialize(JsonObject* json){};

        // void serialize(JsonObject* json){};

        void reset(){};

        string toString() { return ""; };

        void fromString(string){};
};

template <>
struct ConfigVar<string> : BaseVar {
        string* pointer;
        string defaultValue;

        ConfigVar(string n, string* p) {
            name = n;
            pointer = p;
            defaultValue = *p;
        };

        // void deserialize(JsonObject* json) {
        //     if (json->containsKey(name) && json->is<char*>(name)) {
        //         *pointer = string{json->get<char*>(name)};
        //         json->remove(name);
        //     }
        // }

        // void serialize(JsonObject* json) {
        //     json->set(name, *pointer);
        // }

        void reset() { *pointer = defaultValue; }

        string toString() { return *pointer; }

        void fromString(string value) { *pointer = value; }
};

template <>
struct ConfigVar<bool> : BaseVar {
        bool* pointer;
        bool defaultValue;

        ConfigVar(string n, bool* p) {
            name = n;
            pointer = p;
            defaultValue = *p;
        };

        // void deserialize(JsonObject* json) {
        //     if (json->containsKey(name) && json->is<bool>(name)) {
        //         *pointer = json->get<bool>(name);
        //         json->remove(name);
        //     }
        // }

        // void serialize(JsonObject* json) {
        //     json->set(name, *pointer);
        // }

        void reset() { *pointer = defaultValue; }

        string toString() { return *pointer ? "true" : "false"; }

        void fromString(string value) { *pointer = value == "true"; }
};

template <>
struct ConfigVar<int> : BaseVar {
        int* pointer;
        int defaultValue;

        ConfigVar(string n, int* p) {
            name = n;
            pointer = p;
            defaultValue = *p;
        };

        // void deserialize(JsonObject* json) {
        //     if (json->containsKey(name) && json->is<int>(name)) {
        //         *pointer = json->get<int>(name);
        //         json->remove(name);
        //     }
        // }

        // void serialize(JsonObject* json) {
        //     json->set(name, *pointer);
        // }

        void reset() { *pointer = defaultValue; }

        string toString() {
            return NumberToString(
                *pointer);  // string(itoa(pointer));  // string(*pointer);
        }

        void fromString(string value) {
            *pointer = atoi(value.c_str());
            //*pointer = scanf(value, "%d", &pointer);
            //*pointer = stoi(value); // value.toInt();
        }
};

struct ConfigTool {
    public:
        template <typename T>
        void addVariable(string name, T* pointer) {
            variables_[name] = (new ConfigVar<T>(name, pointer));
        };

        void load();
        void save();
        void reset();

    private:
        std::map<string, BaseVar*> variables_;
};
