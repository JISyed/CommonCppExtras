#ifndef CCE_FILE_HEADER
#define CCE_FILE_HEADER

#include <cstdio>

namespace cce
{
	class File
	{
	public:

		enum class Mode
		{
			Read,
			Write,
			ReadAndWrite
		};

		enum class Type
		{
			Text,
			Binary
		};

		enum class Options
		{
			StartOfFile,
			EndOfFile,
			ClearFile
		};

		File(const char* const fileName, const Mode openMode, const Type fileType, const Options fileOptions, const bool fileMustExist = false);
		~File();

		const Mode GetOpenMode() const;
		const Type GetFileType() const;
		const long GetFileSize() const;

	private:

		FILE* handle;
		long fileSize;
		const Mode openMode;
		const Type fileType;

		File() = delete;
		File(const File&) = delete;
		File& operator=(const File&) = delete;
		File(File&&) = delete;
		File& operator=(File&&) = delete;

	};
}

#include "File.inl"
#endif