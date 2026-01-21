Ok so this is an app for coaching in league. Ideally what we would like to do is to take a screenshot of the 
game status every second. When we have 5 frames, we will make a call to an LLM to parse the information and
then give us tips. Such as: the correct build path against the opposing team is ... or the enemy jungler is
likely going to be here etc. It basically will provide the user with a bunch of signals that will improve their gameplay.
<br>
Of course this could be construed as a cheating tool, but it is educational and is designed to assist
players with recognising how they should be analysing the game to make better macro plays. 
<br>
The program is not complicated at all. Basically we will have two entities running. One entity A is constantly
taking screenshots and giving it to entity B. Entity B will collect these screenshots and then once it has 5
frames it will give these screenshots to the LLM. Perhaps one day we will train our own model, for now we will
just use a free gemini API or something along those lines. Could be cool to make our own RAG (retrieval augmented generation)
<br> 
We need someway to display the AI output. For now we will just output it in the terminal. Also where do we store the screenshots?
We will just save them in a temp directory, we must make sure to delete the directory after ending program. Hence we need 
some mechanism to signify program end and allow clean up
<br>
PHASE 1:
Get basic screenshot_agent, controller, coach functionality running. Make sure
cMake can at least run. No error handling
PHASE 2:
Testing. Try actually use it and see what happens. Output to terminal (cout). Add error handling 
(use AI for this, make sure git is set up at this point so we can review AI changes)
PHASE 3:
Refine prompt so that it is more useful
PHASE 4:
Vibecode a frontend, hit gold or plat
<br>
Next possible project idea: a news trader. Determines if a piece of news is novel - 
aka has not been reported before. Determine what cryptos this may impact, and performs
sentiment analysis on whether this will be positive or negative. Then trading on it.

