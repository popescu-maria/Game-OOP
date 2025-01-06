#include "../Headers/Exceptions.h"

generalException::generalException(const std::string& error)
    : std::runtime_error(std::string ("Game error: ") + error) {}

missingTexture::missingTexture(const std::string& error)
    : generalException(error) {}

missingFalsifier::missingFalsifier(const std::string& error)
    : generalException(error) {}

missingDoc::missingDoc(const std::string& error)
    : generalException(error) {}

missingFont::missingFont(const std::string& error)
    : generalException(error) {}

