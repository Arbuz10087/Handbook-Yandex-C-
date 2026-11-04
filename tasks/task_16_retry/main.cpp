#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, 
int retryCount, int sleepTime, bool throwLast) {
    while (retryCount >=0) {
    try {
        Result result = func();
        return result;
    } catch (Exception& ex){
        if (retryCount == 0 && throwLast) {
            throw;
        }

        if (retryCount == 0 && !throwLast) {
            return std::nullopt;
        }
        Sleep(sleepTime);
        --retryCount;
    }
    }
    return Result{};
}