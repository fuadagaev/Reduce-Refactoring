<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta charset="utf-8" />
	<title>Obtaining REDUCE</title>
	<link rel="icon" type="image/png" href="images/icon.png" />
	<link rel="stylesheet" href="StyleSheet.css" />
	<style type="text/css">
		#main img.sflogo {
			float: none;
			margin: auto;
		}
	</style>
</head>
<body>
	<div id="content">
		<header>Obtaining REDUCE</header>
		<div id="middle">
			<nav>
				<script language="php">
					include 'navigation.inc';
				</script>
			</nav>
			<div id="main">
				<p>
					The REDUCE computer algebra system is released free-of-charge under a modified BSD <a href="license.php">license</a> and can be obtained in <a href="versions.php">various versions</a> from <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
						<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a>, as explained below.
				</p>
				<h2>The easy way to obtain REDUCE</h2>
				<p>
					This is to download and install a pre-packaged REDUCE release that contains all necessary binary files as well as documentation (and the main REDUCE source code). We currently release REDUCE in this way primarily for Microsoft Windows, Apple MacOS and GNU/Linux. This approach should work well if you use a supported platform and don't need the very latest version. Simply click on the <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
						<img class="sflogo" alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=10&group_id=248416"></a> logo to visit the project page and then, towards the top of the page, you should see a green box containing the word Download with a filename below it. SourceForge uses heuristics to pick automatically a recent distribution file with an appropriate extension for your platform (although it might get it wrong). You should see a filename of the form:
				</p>
				<ul>
					<li>on Microsoft Windows: Reduce-Setup_<em>yyyy-mm-dd</em>.exe</li>
					<li>on Apple MacOS: Reduce-snapshot_<em>yyyy-mm-dd</em>.dmg</li>
				</ul>
				<p>
					where <em>yyyy-mm-dd</em> represents the release date in numerical format.
				</p>
				<p>
					Download the recommended file to your computer and install it in the normal way: on Windows, double-click the installer file to execute it; on MacOS, double-click the installer file to open it and drag the REDUCE icon to your Applications folder. This process will install both the PSL and the CSL versions of REDUCE, which can be run like any other application; for example, on Windows the Start menu will contain a folder called Reduce that contains applications called CSL Reduce and PSL Reduce, which can be run by clicking on them.
				</p>
				<p>
					Below the green box is a link labelled Browse All Files, and clicking on either that link or the Files link on the toolbar takes you to a page offering recent REDUCE releases for all supported platforms. Each release is a directory, which normally contains the Windows and MacOS distribution files as described above plus a generic source code bundle in the form of a <a href="https://en.wikipedia.org/wiki/Tar_(computing)">compressed tar archive</a> and sets of distribution files for GNU/Linux in the form of <a>compressed tar archives</a>, <a href="https://en.wikipedia.org/wiki/Rpm_(software)">.rpm files</a> and <a href="https://en.wikipedia.org/wiki/Deb_(file_format)">.deb files</a>. These sets of files include separate distribution files for CSL and PSL, for Intel and AMD processors and for 32- and 64-bit architectures. You need to choose and install the right files for your computer.
				</p>
				<p>
					On a platform for which we do not currently provide REDUCE releases, such as Android, the green box will instead be blue and labelled Browse Code. Clicking on it takes you to the Subversion code repository (where you may or may not find source code for a particular platform).
				</p>
				<p>
					Note that we do not provide any automatic update facility; to update REDUCE just install it again. This is probably a good idea every year or so, or if you have encountered errors (and especially if you believe they have been fixed).
				</p>
				<h2>The hard way to obtain REDUCE</h2>
				<p>If the easy way doesn't work for you for some reason then you have the option of building REDUCE yourself from the source code. For guidance on doing this, please see Chapter 2 of <a href="lisp-docs/insidereduce.pdf">Inside Reduce</a>.</p>
				<p>There are also <a href="downloading.php">brief general installation instructions</a> for all platforms and <a href="windows.php">installation instructions for Microsoft Windows users</a>, but these documents are older and now somewhat out of date.</p>
			</div>
			<!--/#main-->
		</div>
		<!--/#middle-->
	</div>
	<!--/#content-->
</body>
</html>
