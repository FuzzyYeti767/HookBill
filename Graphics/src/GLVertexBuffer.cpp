#include"GLVertexBuffer.h"
#include"glCheck.h"
GLVertexBuffer::GLVertexBuffer(GLsizei size_in_bytes)
{
	size = size_in_bytes;
	
	glCheck(glCreateBuffers(1, &buffer_handle));
	glCheck(glNamedBufferStorage(buffer_handle, size, nullptr, GL_DYNAMIC_STORAGE_BIT));

}

GLVertexBuffer::~GLVertexBuffer()
{
	glCheck(glDeleteBuffers(1,&buffer_handle));
}

GLVertexBuffer::GLVertexBuffer(GLVertexBuffer&& temp) noexcept
{
	size = temp.size;
	buffer_handle = temp.buffer_handle;
	temp.size = 0;
	temp.buffer_handle = 0;

}

GLVertexBuffer& GLVertexBuffer::operator=(GLVertexBuffer&& temp) noexcept
{
	// TODO: insert return statement here
	if (this != &temp) {
		size = 0;
		size = temp.size;
		buffer_handle = temp.buffer_handle;
	}
	return *this;
}

void GLVertexBuffer::Use(bool bind) const
{
	if (bind == true)
	{
		glCheck(glBindBuffer(GL_ARRAY_BUFFER,buffer_handle));
	}
	else
	{
		glCheck(glBindBuffer(0, buffer_handle));
	}
}

void GLVertexBuffer::send_buffer_data_to_gpu(const void* data, GLsizei size_bytes, GLsizei starting_offset) const
{
	glCheck(glNamedBufferSubData(buffer_handle, starting_offset, size_bytes, data));
}
