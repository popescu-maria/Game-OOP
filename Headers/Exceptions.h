#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class generalException : public std::runtime_error {
public:
    explicit generalException(const std::string& error);
};

class missingTexture : public generalException {
public:
    explicit missingTexture(const std::string& error);
};

class missingFalsifier : public generalException {
public:
    explicit missingFalsifier(const std::string& error);
};

class missingDoc : public generalException {
public:
    explicit missingDoc(const std::string& error);
};

class missingFont : public generalException {
public:
    explicit missingFont(const std::string& error);
};