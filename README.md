# Background
Ok, this is an app for game analysis in league. Ideally what we would like to do is to take a screenshot of the 
game status every second. When we have 5 frames, we will make a call to an LLM to parse the information and
then give us insights. Such as: the correct build path against the opposing team is ... or the enemy jungler is
likely going to be here etc. It basically will provide the user with a bunch of signals that will help 
them determine how the game might progress.
<br><br>
Note: this doesn't have to be used for league, it could be used for sports games, a presidential debate. Anything
that you can watch in real time on your device.
<br><br>
The program is not complicated at all. Basically we will have two entities running. One entity A is constantly
taking screenshots and giving it to entity B. Entity B will collect these screenshots and then once it has 5
frames it will give these screenshots to the LLM. The goal is to decouple entity B such that one can add a new 
entity with relative ease (a league entity, a sports entity etc.).
Perhaps one day we will train our own model, for now we will just use a free gemini API or something along those lines. 
Training our model does seem a bit crazy, instead what could be cool is making our own RAG (retrieval augmented generation). 
<br><br>
We need someway to display the AI output. For now we will just output it in the terminal. We also need to store the screenshots.
We will just save them in a temp directory, we must make sure to delete the directory after ending program. Hence we need 
some mechanism to signify program end and allow clean up.
<br><br>
The idea is that one should use this as a coach of sorts to improve their own analytical abilities.
# Development Phases
## PHASE 1:
Get basic screenshot_agent, controller, analyst functionality running. No error handling or testing. 
For now we will store all chat history for genai.
## PHASE 2:
Testing and error handling
(use AI for this, make sure git is set up at this point so we can review AI changes)
## PHASE 3:
Optimise prompt, explore the non-essential features (cool to have things like a RAG, 
taking screenshots using the mac API rather than a shell command etc.)
## PHASE 4:
Vibecode a frontend, then using our learnings we can hit plat with ease
# Development journal
How do we maintain a the chat history with the LLM API? Doesn't look like there is 
CPP support (for gemini at least, gemini is the only free one). There are a couple ideas
here, write a python server / library and make calls to it from LeagueAnalyst. Can also we
simply maintain the chat history in some struct. This begs the question though, what information
are we storing abou the chat history? If we store all the images and all the responses this seems
like in a 30 minutes league game, the costs would blow up. Pro games tend to not be that long, 
but regardless resurces usage is something we should consider.
<br><br>
Another problem... The per day request limits are so low! Gemini will give you about 20 requests
a day for each of their models. However, it is unique to each model soooo perhaps we will unify
model calls in another entity C. We can call this entity model_dispatch. It will evaluate 
our rate limits for models that are good enough to produce real output for our use case. Then 
it will make calls to them.
# Random Unrelated Idea Dump
Next possible project idea: a news trader. Determines if a piece of news is novel - 
aka has not been reported before. Determine what cryptos this may impact, and performs
sentiment analysis on whether this will be positive or negative. Then trading on it.
