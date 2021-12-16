#include <exception>
#include <string>

namespace segeom {
  /**
   * @brief An exception thrown when a geometric operation is not allowed or returned an invalid
   *        result.
   */
  class GeometryException : public std::exception {
  public:
    GeometryException(const char *message) : message_(message){};
    const char *what() const throw() { return message_; };

  private:
    const char *message_;
  };
} // namespace segeom