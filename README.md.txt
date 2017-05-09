1, synchronization from fork on github
https://help.github.com/articles/syncing-a-fork
http://share.ez.no/blogs/virgil-ciobanu/how-to-syncronize-your-github-fork-with-original-repository
Command lists:
	=> Setup
	1) git remote -v 
origin	git@github.com:llv22/iOS-SDK.git (fetch)
origin	git@github.com:llv22/iOS-SDK.git (push)
	2) git remote add upstream git@github.com:Estimote/iOS-SDK.git
	3) git remote -v
origin	git@github.com:llv22/iOS-SDK.git (fetch)
origin	git@github.com:llv22/iOS-SDK.git (push)
upstream	git@github.com:Estimote/iOS-SDK.git (fetch)
upstream	git@github.com:Estimote/iOS-SDK.git (push)

	=> Syncing
	1) git fetch upstream
From github.com:Estimote/iOS-SDK
 * [new branch]      gh-pages   -> upstream/gh-pages
 * [new branch]      master     -> upstream/master

	=> Merging

2, more functionalities from estimote.com SDK fro 2.0-beta branch
resource link: https://twitter.com/i/redirect?url=https%3A%2F%2Ftwitter.com%2FEstimote%2Fstatus%2F451026295602704385%3Frefsrc%3Demail&t=1&sig=ae936a3438b8fd6c9e50c0e8b25bfdef2fbbeab1&iid=b04981c9252d4a9ba1ae66ea1241b4b8&uid=772930886&nid=12+1489+20140403
git checkout -b fix_stuff origin/fix_stuff
fetch remote branch - https://help.github.com/articles/fetching-a-remote & http://www.cnblogs.com/hanxianlong/archive/2012/09/10/2678659.html & http://stackoverflow.com/questions/1783405/git-checkout-remote-branch

Orlando's Mac:iOS-SDK llv22$ git remote
origin
upstream
Orlando's Mac:iOS-SDK llv22$ git fetch upstream
