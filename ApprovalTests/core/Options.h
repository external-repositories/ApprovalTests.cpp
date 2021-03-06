#pragma once

#include <utility>
#include <exception>

#include "scrubbers/Scrubbers.h"
#include "core/Reporter.h"
#include "utilities/Macros.h"

namespace ApprovalTests
{
    class Options
    {
    public:
        class FileOptions
        {
            const Options* options_ = nullptr; // set in Options::fileOptions()
            std::string fileExtensionWithDot_ = ".txt";
            friend class Options;

            FileOptions() = default;

            explicit FileOptions(std::string fileExtensionWithDot);

            APPROVAL_TESTS_NO_DISCARD
            FileOptions clone() const;

        public:
            APPROVAL_TESTS_NO_DISCARD
            const std::string& getFileExtension() const;

            APPROVAL_TESTS_NO_DISCARD
            Options withFileExtension(const std::string& fileExtensionWithDot) const;
        };

    private:
        FileOptions fileOptions_;
        Scrubber scrubber_ = Scrubbers::doNothing;
        const Reporter& reporter_ = defaultReporter();
        bool usingDefaultScrubber_ = true;

        Options(FileOptions fileOptions,
                Scrubber scrubber,
                const Reporter& reporter,
                bool usingDefaultScrubber);

        APPROVAL_TESTS_NO_DISCARD
        Options clone(const FileOptions& fileOptions) const;

        static const Reporter& defaultReporter();

    public:
        Options() = default;

        explicit Options(Scrubber scrubber);

        explicit Options(const Reporter& reporter);

        APPROVAL_TESTS_NO_DISCARD
        FileOptions fileOptions() const;

        APPROVAL_TESTS_NO_DISCARD
        Scrubber getScrubber() const;

        APPROVAL_TESTS_NO_DISCARD
        bool isUsingDefaultScrubber() const;

        APPROVAL_TESTS_NO_DISCARD
        std::string scrub(const std::string& input) const;

        APPROVAL_TESTS_NO_DISCARD
        const Reporter& getReporter() const;

        APPROVAL_TESTS_NO_DISCARD
        Options withReporter(const Reporter& reporter) const;

        APPROVAL_TESTS_NO_DISCARD
        Options withScrubber(Scrubber scrubber) const;
    };

    namespace Detail
    {
        //! Helper to prevent compilation failure when types are wrongly treated as Option
        //  or Reporter:
        template <typename T, typename R = void>
        using EnableIfNotOptionsOrReporter = typename std::enable_if<
            (!std::is_same<Options, typename std::decay<T>::type>::value) &&
                (!std::is_base_of<Reporter, typename std::decay<T>::type>::value),
            R>::type;
    } // namespace Detail
}
