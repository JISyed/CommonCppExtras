#include <cassert>

namespace cce
{
	inline File::File(const char* const filename, 
					  const Mode openMode, 
					  const Type fileType, 
					  const Options fileOptions, 
					  const bool fileMustExist)
	{
		assert(filename != nullptr);	// Null string!
		assert(filename[0] != '\0');	// Empty string!

		// Check if the file exists
		if (fileMustExist)
		{
			this->handle = 0;
			fopen_s(&handle, filename, "r");
			assert(this->handle != 0);	// File doesn't exist when it must
			if (this->handle == 0)
			{
				perror("File not found");
				// Exit execution here on error
			}

			fclose(handle);
			this->handle = 0;
		}

		const char* cmodes[12];
		cmodes[0] = "r";	// Read Text
		cmodes[1] = "w";	// Clear & Write Text
		cmodes[2] = "a";	// Write Text
		cmodes[3] = "r+";	// Read/Write Text At Start
		cmodes[4] = "w+";	// Clear & Read/Write Text
		cmodes[5] = "a+";	// Read/Write Text At End
		cmodes[6] = "rb";	// Read Binary
		cmodes[7] = "wb";	// Clear & Write Binary
		cmodes[8] = "ab";	// Write Binary
		cmodes[9] = "rb+";	// Read/Write Binary At Start
		cmodes[10] = "wb+";	// Clear & Read/Write Binary
		cmodes[11] = "ab+";	// Read/Write Binary At End

		const char* currMode = 0;

		// Determing the C Mode String,
		// depending on read, write, or read/write
		if (openMode == Mode::Read)
		{
			if (fileType == Type::Text)
			{
				currMode = cmodes[0];
			}
			else if (fileType == Type::Binary)
			{
				currMode = cmodes[6];
			}
			else
			{
				assert((int)fileType == -234513); // Invalid Type
			}
		}
		else if (openMode == Mode::Write)
		{
			if (fileType == Type::Text)
			{
				currMode = cmodes[2];
			}
			else if (fileType == Type::Binary)
			{
				currMode = cmodes[8];
			}
			else
			{
				assert((int)fileType == -234513); // Invalid Type
			}
		}
		else if (openMode == Mode::ReadAndWrite)
		{
			if (fileType == Type::Text)
			{
				currMode = cmodes[5];
			}
			else if (fileType == Type::Binary)
			{
				currMode = cmodes[11];
			}
			else
			{
				assert((int)fileType == -234513); // Invalid Type
			}
		}
		else
		{
			assert((int) openMode == -234513);	// Invalid Mode
		}
		

		// Actually open the file
		fopen_s(&handle, filename, currMode);
		assert(this->handle != 0);	// Error opening the file!
		if (this->handle == 0)
		{
			perror("File opening error");
			// Exit execution here on error!
		}

		// Operate file differently depending on Options
		if (fileOptions == Options::StartOfFile)
		{
			// Seek to beginning of file
			int sc = fseek(handle, 0, SEEK_SET);
			assert(sc == 0);	// Seek error!
		}
		else if (fileOptions == Options::EndOfFile)
		{
			// Seek to end of file
			int sc = fseek(handle, 0, SEEK_END);
			assert(sc == 0);	// Seek error!
		}
		else if (fileOptions == Options::ClearFile)
		{
			// Reopen the file to clear it
			freopen_s(&handle, filename, "wb", handle);
			assert(this->handle != 0);	// Error clearing the file
			if (this->handle == 0)
			{
				perror("File clearing error");
				// Exit execution here on error!
			}

			// Reopen again to the previous file mode
			freopen_s(&handle, filename, currMode, handle);
			assert(this->handle != 0);	// Error reopening the file!
			if (this->handle == 0)
			{
				perror("File reopening error");
				// Exit execution here on error!
			}

		}
		else
		{
			assert((int)fileOptions == -234513); // Invalid Option
		}
	}

	inline File::~File()
	{
		
	}
}