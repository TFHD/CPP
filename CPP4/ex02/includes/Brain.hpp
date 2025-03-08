#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        Brain(const Brain &cpy);
        Brain &operator=(const Brain &src);
        ~Brain(void);
        void        setIdea(int i, std::string);
        const std::string getIdea(int i) const;
};

#endif