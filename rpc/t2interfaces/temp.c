
int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (INT2, VERSIONINT2);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, INT2, VERSIONINT2, int2_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (INT2, VERSIONINT2, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, INT2, VERSIONINT2, int2_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (INT2, VERSIONINT2, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
