#pragma once

#include <vector>
#include <string>
#include <optional>
#include <sstream>

class Options
{
    std::vector<std::string> m_options;

public:
    Options(int argc, char *argv[]) : m_options(std::vector<std::string>(&argv[0], &argv[0] + argc)) {}

    bool Has(const std::string &option) const { return Find(option, false).has_value(); }
    std::string String(const std::string &option, const std::string &default) const;
    int Int(const std::string &option, int default) const;
    double Double(const std::string &option, double default) const;
    bool Bool(const std::string &option, bool default) const;
    std::vector<std::string> StringVector(const std::string &option, const std::vector<std::string> &default) const;

private:
    std::optional<std::string> Find(const std::string &option, bool next = true) const;
};