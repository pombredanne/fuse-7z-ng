/*
 * This file is part of fuse-7z-ng.
 *
 * fuse-7z-ng is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * fuse-7z-ng is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with fuse-7z-ng.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <ctime>
#include <cstring>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _LFS_LARGEFILE
typedef off64_t offset_t;
#else
typedef off_t offset_t;
#endif

class Node;
class Fuse7z;
class BigBuffer;

class Fuse7z {
	private:
	public:
	std::string const archive_fn;
	std::string const cwd;
	Node * root_node;

	public:
	Fuse7z(std::string const & filename, std::string const & cwd);
	virtual ~Fuse7z();

	virtual void open(char const * path, Node * n) = 0;
	virtual void close(char const * path, Node * n) = 0;
	virtual int read(char const * path, Node * node, char * buf, size_t size, off_t offset) = 0;

};


