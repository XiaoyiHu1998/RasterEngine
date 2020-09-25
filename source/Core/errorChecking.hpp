#ifndef ERROR_CHECKING
#define ERROR_CHECKING

static void GLClearError(){
    while(glGetError() != GL_NO_ERROR);     //same as having {} as loop body
}

static std::string glErrorString(GLenum error){
    switch(error){
        case GL_NO_ERROR:           return "GL_NO_ERROR";
        case GL_INVALID_ENUM:       return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE:      return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION:  return "GL_INVALID_OPERATION";
        case GL_STACK_OVERFLOW:     return "GL_STACK_OVERFLOW";
        case GL_STACK_UNDERFLOW:    return "GL_STACK_UNDERFLOW";
        case GL_OUT_OF_MEMORY:      return "GL_OUT_OF_MEMORY";
        default:                    return "GL_UNKOWN_ERROR";
    }
}

static std::string getFileName(const char* file){
    std::string path = file;
    return path.substr(path.find_last_of('\\') + 1);
}

static bool GLLogCall(const char* function, const char* path, int line){
    if(GLenum glError = glGetError()){     //assigns the errorcode to error and uses it to evaluate loop condition
        std::cout << "[OpenGL Error] (0x0" << std::hex << glError << std::dec << ": " << glErrorString(glError) << ") -> " << function << ", " << path << ":" << line <<std::endl;
        return false;
    }
    return true;
}

#define RE_ASSERT(x) if(!(x)); //exit(-1) should be replaced with a breakstatement

#ifdef RE_DEBUG //GLCall
    #define GLCall(x) GLClearError(); x; RE_ASSERT(GLLogCall(#x, __FILE__, __LINE__)) 
#else
    #define GLCall(x) x
#endif // RE_DEBUG


static void outputBufferState(){
    std::vector<GLenum> bufferValues = {GL_BUFFER_ACCESS, GL_BUFFER_MAPPED, GL_BUFFER_SIZE, GL_BUFFER_USAGE};
    int bufferValue = 0;
    std::cout << "vertexBuffer:" << std::endl;
    for(GLenum value : bufferValues){
        GLCall(glGetBufferParameteriv(GL_ARRAY_BUFFER, value, &bufferValue));
        switch(value){
            case GL_BUFFER_ACCESS:  std::cout << "bufferAccess == GL_READ_WRITE: "  << (bufferValue == GL_READ_WRITE)    << std::endl;     break;
            case GL_BUFFER_MAPPED:  std::cout << "bufferMapped == GL_FALSE: "       << (bufferValue == GL_FALSE)         << std::endl;     break;
            case GL_BUFFER_SIZE:    std::cout << "bufferSize: "                     << bufferValue                       << std::endl;     break;
            case GL_BUFFER_USAGE:   std::cout << "bufferUseage == GL_STATIC_DRAW: " << (bufferValue == GL_STATIC_DRAW)   << std::endl;     break;
            default:                break;
        }
    }
}

#endif //ERROR_CHECKING