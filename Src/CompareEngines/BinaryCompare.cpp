/**
 * @file  BinaryCompare.cpp
 *
 * @brief Implementation file for BinaryCompare
 */

#include "BinaryCompare.h"
#include "DiffItem.h"
#include "PathContext.h"
#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif
#include <fcntl.h>

namespace CompareEngines
{

BinaryCompare::BinaryCompare()
{
}

BinaryCompare::~BinaryCompare()
{
}

static int compare_files(const String& file1, const String& file2)
{
	const size_t bufsize = 1024 * 256;
	int code;
	int fd1 = _topen(file1.c_str(), O_BINARY | O_RDONLY);
	int fd2 = _topen(file2.c_str(), O_BINARY | O_RDONLY);
	if (fd1 != -1 && fd2 != -1)
	{
		for (;;)
		{
			char buf1[bufsize];
			char buf2[bufsize];
			int size1 = read(fd1, buf1, sizeof(buf1));
			int size2 = read(fd2, buf2, sizeof(buf2));
			if (size1 <= 0 || size2 <= 0)
			{
				if (size1 < 0 || size2 < 0)
					code = DIFFCODE::CMPERR;
				else
					code = DIFFCODE::SAME;
				break;
			}
			if (size1 != size2 || memcmp(buf1, buf2, size1) != 0)
			{
				code = DIFFCODE::DIFF;
				break;
			}
		}
	}
	else
	{
		code = DIFFCODE::CMPERR;
	}
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);

	return code;
}

/**
 * @brief Compare two specified files, byte-by-byte
 * @param [in] di Diffitem info.
 * @return DIFFCODE
 */
int BinaryCompare::CompareFiles(const PathContext& files, const DIFFITEM &di) const
{
	switch (files.GetSize())
	{
	case 2:
		return di.diffFileInfo[0].size != di.diffFileInfo[1].size ? 
			DIFFCODE::DIFF : compare_files(files[0], files[1]);
	case 3:
		unsigned code10 = (di.diffFileInfo[1].size != di.diffFileInfo[0].size) ?
			DIFFCODE::DIFF : compare_files(files[1], files[0]);
		unsigned code12 = (di.diffFileInfo[1].size != di.diffFileInfo[2].size) ?
			DIFFCODE::DIFF : compare_files(files[1], files[2]);
		unsigned code02 = DIFFCODE::SAME;
		if (code10 == DIFFCODE::SAME && code12 == DIFFCODE::SAME)
			return DIFFCODE::SAME;
		else if (code10 == DIFFCODE::SAME && code12 == DIFFCODE::DIFF)
			return DIFFCODE::DIFF | DIFFCODE::DIFF3RDONLY;
		else if (code10 == DIFFCODE::DIFF && code12 == DIFFCODE::SAME)
			return DIFFCODE::DIFF | DIFFCODE::DIFF1STONLY;
		else if (code10 == DIFFCODE::DIFF && code12 == DIFFCODE::DIFF)
		{
			code02 = di.diffFileInfo[0].size != di.diffFileInfo[2].size ?
				DIFFCODE::DIFF : compare_files(files[0], files[2]);
			if (code02 == DIFFCODE::SAME)
				return DIFFCODE::DIFF | DIFFCODE::DIFF2NDONLY;
		}
		if (code10 == DIFFCODE::CMPERR || code12 == DIFFCODE::CMPERR || code02 == DIFFCODE::CMPERR)
			return DIFFCODE::CMPERR;
		return DIFFCODE::DIFF;
	}
	return DIFFCODE::CMPERR;
}

} // namespace CompareEngines
